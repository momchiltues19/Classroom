class MemberTeamsController < ApplicationController
  before_action :set_member_team, only: [:show, :edit, :update, :destroy]

  # GET /member_teams
  # GET /member_teams.json
  def index
    @member_teams = MemberTeam.all
  end

  # GET /member_teams/1
  # GET /member_teams/1.json
  def show
  end

  # GET /member_teams/new
  def new
    @member_team = MemberTeam.new
  end

  # GET /member_teams/1/edit
  def edit
  end

  # POST /member_teams
  # POST /member_teams.json
  def create
    @member_team = MemberTeam.new(member_team_params)

    respond_to do |format|
      if @member_team.save
        format.html { redirect_to @member_team, notice: 'Member team was successfully created.' }
        format.json { render :show, status: :created, location: @member_team }
      else
        format.html { render :new }
        format.json { render json: @member_team.errors, status: :unprocessable_entity }
      end
    end
  end

  # PATCH/PUT /member_teams/1
  # PATCH/PUT /member_teams/1.json
  def update
    respond_to do |format|
      if @member_team.update(member_team_params)
        format.html { redirect_to @member_team, notice: 'Member team was successfully updated.' }
        format.json { render :show, status: :ok, location: @member_team }
      else
        format.html { render :edit }
        format.json { render json: @member_team.errors, status: :unprocessable_entity }
      end
    end
  end

  # DELETE /member_teams/1
  # DELETE /member_teams/1.json
  def destroy
    @member_team.destroy
    respond_to do |format|
      format.html { redirect_to member_teams_url, notice: 'Member team was successfully destroyed.' }
      format.json { head :no_content }
    end
  end

  private
    # Use callbacks to share common setup or constraints between actions.
    def set_member_team
      @member_team = MemberTeam.find(params[:id])
    end

    # Never trust parameters from the scary internet, only allow the white list through.
    def member_team_params
      params.require(:member_team).permit(:member_id, :team_id)
    end
end
